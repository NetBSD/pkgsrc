# $NetBSD: Makefile,v 1.66 2006/02/05 22:45:53 joerg Exp $

DISTNAME=		gettext-0.14.5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gettext/gettext.html
COMMENT=		Tools for providing messages in different languages

DEPENDS+=			gettext-m4-0.14.5:../../devel/gettext-m4
DEPENDS+=			gettext-tools-0.14.5:../../devel/gettext-tools
BUILDLINK_DEPENDS.gettext+=	gettext-lib>=0.14.5

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool
CONFIGURE_ARGS+=	--without-included-gettext

CONFIGURE_ENV+=		GCJ= ac_cv_prog_GCJ=
CONFIGURE_ENV+=		HAVE_GCJ_IN_PATH=
CONFIGURE_ENV+=		HAVE_JAVAC_IN_PATH=
CONFIGURE_ENV+=		HAVE_JIKES_IN_PATH=

TEST_TARGET=		check

BROKEN_GETTEXT_DETECTION=	yes
USE_BUILTIN.gettext=	no # force use of pkgsrc gettext-lib

do-install:
	cd ${WRKSRC}/gettext-tools && ${MAKE} install-gettextsrcSCRIPTS
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gettext
	cd ${WRKSRC}/gettext-tools/lib && ${MAKE} install-gettextsrcDATA
	cd ${WRKSRC}/gettext-tools/projects && ${MAKE} install
	cd ${WRKSRC}/gettext-tools/misc && ${MAKE} install
	cd ${WRKSRC}/gettext-tools/src && ${MAKE} install-tcl install-exec-local
	cd ${WRKSRC}/gettext-runtime && ${MAKE} install-gettextsrcDATA
	cd ${WRKSRC}/gettext-tools/intl && ${MAKE} install-exec install-data
	cd ${WRKSRC}/gettext-tools/po && ${MAKE} installdirs-data install-data
	${INSTALL_DATA_DIR} ${MANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/gettext-tools/man/autopoint.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/gettext-tools/man/gettextize.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-asprintf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
