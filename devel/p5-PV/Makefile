# $NetBSD: Makefile,v 1.10 2001/10/18 15:20:18 veego Exp $
# FreeBSD Id: Makefile,v 1.4 1997/06/24 18:43:28 jfitz Exp
#

DISTNAME=	PerlVision-1.4
PKGNAME=	p5-PV-1.4
SVR4_PKGNAME=	p5pvi
CATEGORIES=	devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PV/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl5 library for text-mode user interface widgets

DEPENDS+=	p5-Curses>=1.02:../../devel/p5-Curses

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/PV/.packlist

pre-configure:
	@${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
