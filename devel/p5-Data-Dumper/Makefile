# $NetBSD: Makefile,v 1.17 2001/07/09 16:59:54 tv Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/24 18:43:11 jfitz Exp

DISTNAME=	p5-Data-Dumper-2.102nb1
CATEGORIES=	devel
DISTFILES=	# empty

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.perldoc.com/perl5.6/lib/Data/Dumper.html
COMMENT=	perl5 module for stringified perl data structures

# This version of Data::Dumper is already in lang/perl5; this pkg is
# here to provide a dependency point.  An explicit Perl version
# number is used here to correspond with the Data::Dumper version above.

DEPENDS+=	perl-base-5.6.1*:../../lang/perl5-base

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined

do-build do-install: # (do nothing)

.include "../../mk/bsd.pkg.mk"
