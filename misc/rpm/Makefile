# $NetBSD: Makefile,v 1.32 2001/10/24 00:26:51 lukem Exp $
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

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/rpm
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
