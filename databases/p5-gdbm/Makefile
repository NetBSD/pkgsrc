# $NetBSD: Makefile,v 1.25 2005/04/11 21:45:13 tv Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=		p5-gdbm-1.05
PKGREVISION=		3
SVR4_PKGNAME=		p5gdm
CATEGORIES+=		databases

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl interface to gdbm - GNU database manager

WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GDBM_File/.packlist

EXTRACT_ELEMENTS=	${DISTNAME}/ext/GDBM_File

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
