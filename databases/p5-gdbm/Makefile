# $NetBSD: Makefile,v 1.12 2001/10/18 15:20:10 veego Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=		p5-gdbm-1.05
SVR4_PKGNAME=		p5gdm
CATEGORIES+=		perl5

MAINTAINER=		packages@netbsd.org
COMMENT=		perl interface to gdbm - GNU database manager

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GDBM_File/.packlist

EXTRACT_ELEMENTS=	${DISTNAME}/ext/GDBM_File
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../databases/gdbm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
