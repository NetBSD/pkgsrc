# $NetBSD: Makefile,v 1.35 2001/04/22 06:28:30 jlam Exp $

DISTNAME=		perl-5.6.0nb5
CATEGORIES=		lang devel perl5
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html
COMMENT=		Practical Extraction and Report Language

DEPENDS+=		perl-base>=5.6.0nb1:../../lang/perl5-base
DEPENDS+=		p5-Data-Dumper>=2.101:../../devel/p5-Data-Dumper
DEPENDS+=		p5-Devel-DProf>=19990108:../../devel/p5-Devel-DProf
DEPENDS+=		p5-Devel-Peek>=1.0001:../../devel/p5-Devel-Peek
DEPENDS+=		p5-CGI>=2.56:../../www/p5-CGI
DEPENDS+=		perl-mk-1.1:../../pkgtools/perl-mk

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		# defined
NO_PATCH=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
