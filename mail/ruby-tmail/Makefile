# $NetBSD: Makefile,v 1.21 2017/09/04 18:00:57 wiz Exp $

DISTNAME=	tmail-1.2.7.1
PKGREVISION=	2
CATEGORIES=	mail

MAINTAINER=	taca@NetBSD.org
#HOMEPAGE=	http://tmail.rubyforge.org/
COMMENT=	Mail manipulating library for Ruby including MIME multipart support
LICENSE=	mit

# Add a directory that would be created if the setup.rb script was run.
pre-configure:
	cd ${WRKSRC} && mkdir doc
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
