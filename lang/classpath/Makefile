# $NetBSD: Makefile,v 1.4 2004/02/14 17:21:43 jlam Exp $

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

.include "../../mk/bsd.pkg.mk"
