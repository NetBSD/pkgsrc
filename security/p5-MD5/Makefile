# $NetBSD: Makefile,v 1.12 2001/02/17 17:49:59 wiz Exp $
# FreeBSD Id: Makefile,v 1.7 1997/06/24 18:43:23 jfitz Exp
#

DISTNAME=		MD5-1.7
PKGNAME=		p5-MD5-1.7
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MD5/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/MD5/MD5.html
COMMENT=		perl5 interface to the RSA Data Security Inc. MD5 algorithm

CONFLICTS+=		p5-Digest-MD5-[0-9]*

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MD5/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
