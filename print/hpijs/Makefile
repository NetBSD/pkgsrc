# $NetBSD: Makefile,v 1.3 2002/09/13 23:09:32 jlam Exp $

DISTNAME=	hpijs-1.2.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hpinkjet/}

MAINTAINER=	jlam@netbsd.org
COMMENT=	HP inkjet printer driver server
HOMEPAGE=	http://hpinkjet.sourceforge.net/

CONFLICTS=	ghostscript<=6.0.1nb4 ghostscript-nox11<=6.0.1nb4

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
.  include "../../lang/gcc/Makefile.gcc"
.endif

.include "../../mk/bsd.pkg.mk"
