# $NetBSD: Makefile,v 1.1.1.1 2003/06/24 13:36:43 agc Exp $

DISTNAME=		classpath-0.05
CATEGORIES=		devel
MASTER_SITES=		ftp://alpha.gnu.org/gnu/classpath/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/classpath
COMMENT=		Class libraries for Java VM

DEPENDS+=		jikes>=1.18:../../lang/jikes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-jikes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
