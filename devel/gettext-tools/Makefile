# $NetBSD: Makefile,v 1.9 2007/12/21 19:11:38 rillig Exp $

DISTNAME=	gettext-0.14.6
PKGNAME=	gettext-tools-0.14.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gettext/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gettext/gettext.html
COMMENT=	Tools for providing messages in different languages

BUILDLINK_API_DEPENDS.gettext+=	gettext-lib>=0.14.5
CONFLICTS=		gettext<0.14.5

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=		GCJ= ac_cv_prog_GCJ= ac_cv_prog_JAR=
CONFIGURE_ENV+=		HAVE_GCJ_IN_PATH=
CONFIGURE_ENV+=		HAVE_JAVAC_IN_PATH=
CONFIGURE_ENV+=		HAVE_JIKES_IN_PATH=
CONFIGURE_ENV+=		ac_cv_libexpat=no

SHLIBTOOL_OVERRIDE=	# empty
INFO_FILES=		yes
MAKE_JOBS_SAFE=		no

BROKEN_GETTEXT_DETECTION=	yes
USE_BUILTIN.gettext=	no # force use of pkgsrc gettext-lib

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
