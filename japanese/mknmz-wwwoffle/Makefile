# $NetBSD: Makefile,v 1.1.1.1 2001/02/20 10:09:02 kei Exp $
#

DISTNAME=	mknmz-wwwoffle-0.7.0
CATEGORIES=	japanese
MASTER_SITES=	http://www.naney.org/comp/distrib/mknmz-wwwoffle/archive/

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.naney.org/comp/distrib/mknmz-wwwoffle/index.html
COMMENT=	full text indexing and searching system for wwwoffle's cache directory

DEPENDS+=	namazu>=2.0.5:../../japanese/namazu2
DEPENDS+=	wwwoffle>=2.6:../../www/wwwoffle

USE_PERL5=	# defined
GNU_CONFIGURE=	# defined
CONFIG_ARGS+=	--prefix=${PREFIX}/share/namazu

.include "../../mk/bsd.pkg.mk"
