# $NetBSD: Makefile,v 1.8 2000/08/28 19:37:42 jlam Exp $
# FreeBSD Id: Makefile,v 1.4 1997/06/24 18:43:28 jfitz Exp
#

DISTNAME=	PerlVision-1.4
PKGNAME=	p5-PV-1.4
CATEGORIES=	devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PV/}

MAINTAINER=	packages@netbsd.org

DEPENDS+=	p5-Curses>=1.02:../../devel/p5-Curses

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/PV/.packlist

pre-configure:
	@${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
