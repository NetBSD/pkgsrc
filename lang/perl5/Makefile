# $NetBSD: Makefile,v 1.31 2000/09/05 09:20:44 jlam Exp $

DISTNAME=		perl-5.6.0nb3
CATEGORIES=		lang devel perl5
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html

DEPENDS+=		perl-base>=5.6.0:../../lang/perl5-base
DEPENDS+=		p5-Data-Dumper>=2.101:../../devel/p5-Data-Dumper
DEPENDS+=		p5-Devel-DProf>=19990108:../../devel/p5-Devel-DProf
DEPENDS+=		p5-Devel-Peek>=1.0001:../../devel/p5-Devel-Peek
DEPENDS+=		p5-CGI>=2.56:../../www/p5-CGI

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		# defined
NO_PATCH=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
