# $NetBSD: Makefile,v 1.45 2003/04/27 19:18:19 jmmv Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/08/09 15:13:33 kuriyama Exp
#

DISTNAME=		gettext-0.11.5
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gettext/gettext.html
COMMENT=		tools for providing messages in different languages

DEPENDS+=			gettext-m4-0.11.5:../../devel/gettext-m4
BUILDLINK_DEPENDS.gettext=	gettext-lib-0.11.5

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub
USE_GNU_GETTEXT=	yes
CONFIGURE_ARGS+=	--without-included-gettext

INFO_FILES=		gettext.info
TEXINFO_OVERRIDE=	YES

CONFIGURE_ENV+=		GCJ= ac_cv_prog_GCJ=
CONFIGURE_ENV+=		HAVE_GCJ_IN_PATH=
CONFIGURE_ENV+=		HAVE_JAVAC_IN_PATH=
CONFIGURE_ENV+=		HAVE_JIKES_IN_PATH=

post-install:
	cd ${WRKSRC}/intl; ${MAKE_PROGRAM} install-data

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
