# $NetBSD: Makefile,v 1.3 2003/07/17 21:44:07 grant Exp $

DISTNAME=		classpath-0.05
CATEGORIES=		devel
MASTER_SITES=		ftp://alpha.gnu.org/gnu/classpath/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/classpath
COMMENT=		Class libraries for Java VM

DEPENDS+=		jikes>=1.18:../../lang/jikes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-jikes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
