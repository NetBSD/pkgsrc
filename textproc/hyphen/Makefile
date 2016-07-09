# $NetBSD: Makefile,v 1.6 2016/07/09 06:39:06 wiz Exp $

DISTNAME=	hyphen-2.8.6
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hunspell/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://hunspell.sourceforge.net/
COMMENT=	Library for high quality hyphenation and justification
LICENSE=	mpl-1.1 OR gnu-lgpl-v2.1 OR gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gawk patch perl

REPLACE_PERL=	substrings.pl

.include "../../mk/bsd.pkg.mk"
