# $NetBSD: Makefile,v 1.7 2000/08/27 07:11:07 jlam Exp $
# FreeBSD Id: Makefile,v 1.4 1997/06/24 18:43:28 jfitz Exp
#

DISTNAME=	perlvision
PKGNAME=	p5-PV-1.0
CATEGORIES=	devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PV/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org

DEPENDS+=	p5-Curses-1.02:../../devel/p5-Curses

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/PV/.packlist

NO_WRKSUBDIR=	# defined
DOCDIR=		${PREFIX}/share/doc/PerlVision

pre-configure:
	${RM} -f ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/Makefile.PL ${WRKSRC}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/PerlVision.doc ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
