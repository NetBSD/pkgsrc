# $NetBSD: Makefile,v 1.1.1.1 2004/08/29 15:29:04 recht Exp $
# FreeBSD Id: Makefile,v 1.10 1997/04/27 16:06:15 ache Exp
#

DISTNAME=	rzip-2.0
CATEGORIES=	archivers
MASTER_SITES=	http://rzip.samba.org/ftp/rzip/

MAINTAINER=	carton@Ivy.NET
HOMEPAGE=	http://rzip.samba.org/
COMMENT=	Create or extract .rz files, like gzip but smaller

GNU_CONFIGURE=	YES

post-install:
	${LN} -f ${PREFIX}/bin/rzip ${PREFIX}/bin/runzip
	${RM} -f ${PREFIX}/man/man1/runzip.1
	${LN} -s ${PREFIX}/man/man1/rzip.1 ${PREFIX}/man/man1/runzip.1

.include "../../mk/bsd.pkg.mk"
