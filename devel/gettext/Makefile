# $NetBSD: Makefile,v 1.59 2004/04/20 13:36:47 tv Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/08/09 15:13:33 kuriyama Exp
#

DISTNAME=		gettext-0.11.5
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gettext/gettext.html
COMMENT=		Tools for providing messages in different languages

DEPENDS+=			gettext-m4-0.11.5:../../devel/gettext-m4
BUILDLINK_DEPENDS.gettext+=	gettext-lib>=0.11.5

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--without-included-gettext

INFO_FILES=		gettext.info

CONFIGURE_ENV+=		GCJ= ac_cv_prog_GCJ=
CONFIGURE_ENV+=		HAVE_GCJ_IN_PATH=
CONFIGURE_ENV+=		HAVE_JAVAC_IN_PATH=
CONFIGURE_ENV+=		HAVE_JIKES_IN_PATH=

MAKE_ENV+=  		OPSYS="${OPSYS}"

TEST_TARGET=		check

USE_BUILTIN.gettext=	no # force use of pkgsrc gettext-lib

post-install:
	cd ${WRKSRC}/intl; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install-data

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
