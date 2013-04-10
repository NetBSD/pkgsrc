# $NetBSD: Makefile,v 1.1 2013/04/10 00:18:18 rodent Exp $
#

DISTNAME=	aspell6-te-0.01-2
PKGNAME=	${DISTNAME:S/6-/-/1:S/-2/.2/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/te/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
HOMEPAGE=	http://www.swecha.org/wiki/Wordlist_and_Dictionaries
COMMENT=	Telugu language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
