# $NetBSD: Makefile,v 1.37 2002/12/01 16:25:58 salo Exp $
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

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

DEINSTALL_TMPL=		${.CURDIR}/DEINSTALL
INSTALL_TMPL=		${.CURDIR}/INSTALL

# The rpm databases are kept under ${RPM_DB_PREFIX}/lib/rpm.
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
