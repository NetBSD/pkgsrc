# $NetBSD: Makefile,v 1.26 2002/03/20 16:23:07 wiz Exp $
# FreeBSD Id: Makefile,v 1.12 1997/11/22 16:01:32 jseger Exp
#

DISTNAME=		guile-1.4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_GNU_READLINE=	# defined

INFO_FILES=		data-rep.info

.include "../../devel/readline/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
