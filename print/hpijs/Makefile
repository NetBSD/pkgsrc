# $NetBSD: Makefile,v 1.5 2003/01/25 08:51:47 toshii Exp $

DISTNAME=	hpijs-1.3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hpinkjet/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://hpinkjet.sourceforge.net/
COMMENT=	HP inkjet printer driver server

CONFLICTS=	ghostscript<=6.0.1nb4 ghostscript-nox11<=6.0.1nb4

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
.  include "../../lang/gcc/buildlink2.mk"
.endif

.include "../../mk/bsd.pkg.mk"
