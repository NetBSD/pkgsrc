# $NetBSD: Makefile,v 1.19 2000/11/22 21:19:13 wiz Exp $
# FreeBSD Id: Makefile,v 1.12 1997/11/22 16:01:32 jseger Exp
#

DISTNAME=		guile-1.4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		perry@piermont.com
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html

DEPENDS+=		readline>=4.1:../../devel/readline

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
# to find libreadline
CFLAGS+=		-I${PREFIX}/include

INFO_FILES=		data-rep.info

.include "../../mk/bsd.pkg.mk"
