# $NetBSD: Makefile,v 1.13 2001/11/26 06:49:42 jlam Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=		p5-gdbm-1.05
SVR4_PKGNAME=		p5gdm
CATEGORIES+=		perl5

MAINTAINER=		packages@netbsd.org
COMMENT=		perl interface to gdbm - GNU database manager

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GDBM_File/.packlist

EXTRACT_ELEMENTS=	${DISTNAME}/ext/GDBM_File
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../databases/gdbm/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
