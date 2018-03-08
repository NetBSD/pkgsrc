# $NetBSD: Makefile,v 1.44 2018/03/08 14:11:24 mef Exp $
#

DISTNAME=	ngspice-27
PKGNAME=	ng-spice-27
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ngspice/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://ngspice.sourceforge.net/
COMMENT=	Next generation circuit simulation program

USE_LIBTOOL=		YES
USE_TOOLS+=		gmake makeinfo

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--with-readline=yes
LIBS+=			${BUILDLINK_LDADD.getopt}

INFO_FILES=	yes
TEXINFO_REQD=	4.6

.include "../../devel/libgetopt/buildlink3.mk"
# uses rl_* interface
.include "../../devel/readline/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
