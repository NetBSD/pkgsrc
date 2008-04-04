# $NetBSD: Makefile,v 1.4 2008/04/04 15:30:00 jlam Exp $

DISTNAME=	rubyzip-0.9.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby//}
PKGREVISION=	1
CATEGORIES=	archivers

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyzip.sourceforge.net/
COMMENT=	Ruby module for reading and writing zip files

post-extract:
	rm -f ${WRKSRC}/lib/download_quizzes.rb
	rm -fr ${WRKSRC}/lib/quiz1

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
