# $NetBSD: Makefile,v 1.33 2002/04/04 19:56:37 jdolecek Exp $
#

DISTNAME=	rpm-2.5.4
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-2.5.x/ \
		ftp://ftp.gwdg.de/pub/linux/redhat/code/rpm/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.rpm.org/
COMMENT=	The Red Hat Package Manager

BUILD_USES_MSGFMT=	yes

CONFLICTS+=		rpm2cpio<1.0nb1

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BUILDLINK_ONLY=	yes

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

FILES_SUBST=		CAT=${CAT:Q}
FILES_SUBST+=		MKDIR=${MKDIR:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

post-configure:
	cd ${WRKSRC}/po && ( mv cz.mo cs.mo; mv cz.po cs.po )

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/rpm
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
