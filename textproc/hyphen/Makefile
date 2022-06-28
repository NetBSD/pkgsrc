# $NetBSD: Makefile,v 1.13 2022/06/28 11:36:11 wiz Exp $

DISTNAME=	hyphen-2.8.8
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hunspell/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://hunspell.github.io/
COMMENT=	Library for high quality hyphenation and justification
LICENSE=	mpl-1.1 OR gnu-lgpl-v2.1 OR gnu-gpl-v2

USE_LIBTOOL=	yes
USE_TOOLS+=	gawk patch perl
GNU_CONFIGURE=	yes

REPLACE_PERL=	substrings.pl

.include "../../mk/bsd.pkg.mk"
