# $NetBSD: Makefile,v 1.7 2018/01/25 05:46:57 adam Exp $

DISTNAME=	hyphen-2.8.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hunspell/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://hunspell.github.io/
COMMENT=	Library for high quality hyphenation and justification
LICENSE=	mpl-1.1 OR gnu-lgpl-v2.1 OR gnu-gpl-v2

USE_LIBTOOL=	yes
USE_TOOLS+=	gawk patch perl
GNU_CONFIGURE=	yes

REPLACE_PERL=	substrings.pl

.include "../../mk/bsd.pkg.mk"
