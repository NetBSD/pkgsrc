# $NetBSD: Makefile,v 1.5 1999/05/24 20:39:45 tv Exp $
#

DISTNAME=		dync-1.1
CATEGORIES=		misc
MASTER_SITES=		http://www.westley.demon.co.uk/src/

MAINTAINER=		agc@netbsd.org
HOMEPAGE=		http://www.westley.demon.co.uk/software.html

NOT_FOR_PLATFORM=	*-*-alpha	#dync: can't dlopen `lib1.so.1.0'

GNU_CONFIGURE=		yes
ALL_TARGET=		tst

.include "../../mk/bsd.pkg.mk"
