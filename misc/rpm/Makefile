# $NetBSD: Makefile,v 1.35 2002/10/20 23:09:27 jlam Exp $
#

DISTNAME=	rpm-2.5.4
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-2.5.x/ \
		ftp://ftp.gwdg.de/pub/linux/redhat/code/rpm/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.rpm.org/
COMMENT=	The Red Hat Package Manager

CONFLICTS+=		rpm2cpio<1.0nb1

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

DEINSTALL_TMPL=		${.CURDIR}/DEINSTALL
INSTALL_TMPL=		${.CURDIR}/INSTALL

# The rpm databases are kept under ${RPM_DB_PREFIX}/lib/rpm.
RPM_DB_PREFIX?=		${LOCALBASE}
CONFIGURE_ENV+=		varprefix="${RPM_DB_PREFIX}"

RPMDIR=			${RPM_DB_PREFIX}/lib/rpm
FILES_SUBST+=		RPMDIR=${RPMDIR}

post-configure:
	cd ${WRKSRC}/po && ( ${MV} cz.mo cs.mo; ${MV} cz.po cs.po )

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/rpm

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
