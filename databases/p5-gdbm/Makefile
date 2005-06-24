# $NetBSD: Makefile,v 1.26 2005/06/24 06:43:43 jlam Exp $

DISTNAME=	perl-5.6.1
PKGNAME=	p5-gdbm-1.05
SVR4_PKGNAME=	p5gdm
PKGREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES+=	ftp://cpan.teleglobe.net/pub/CPAN/src/5.0/maint/ \
		ftp://perl.secsup.org/pub/perl/src/5.0/maint/ \
		ftp://ftp.lug.udel.edu/pub/CPAN/src/5.0/maint/ \
		ftp://ftp.funet.fi/pub/languages/perl/CPAN/src/5.0/maint/ \
		ftp://ftp.ruhr-uni-bochum.de/mirrors/ftp.funet.fi/pub/languages/perl/CPAN/src/5.0/maint/

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl interface to gdbm - GNU database manager

EXTRACT_ELEMENTS=	${DISTNAME}/ext/GDBM_File
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GDBM_File/.packlist

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
