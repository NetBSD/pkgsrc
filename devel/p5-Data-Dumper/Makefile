# New ports collection makefile for:	p5-Data-Dumper
# Version required:			2.07
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1997/11/22 04:44:06 hubertf Exp $
#

DISTNAME=	Data-Dumper-2.07
PKGNAME=	p5-Data-Dumper-2.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

WRKSRC=		${WRKDIR}/Data-Dumper-2.07
MAN3=		Data::Dumper.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
