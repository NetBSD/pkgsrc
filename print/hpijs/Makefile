# $NetBSD: Makefile,v 1.7 2003/06/02 14:05:07 abs Exp $

DISTNAME=	hpijs-1.3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hpinkjet/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://hpinkjet.sourceforge.net/
COMMENT=	HP inkjet printer driver server

CONFLICTS=	ghostscript<=6.0.1nb4 ghostscript-nox11<=6.0.1nb4

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
CPPFLAGS+=		-DAPDK_BUFFER_SEND

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
.  include "../../mk/gcc.buildlink2.mk"
.endif

.include "../../mk/bsd.pkg.mk"
