# $NetBSD: Makefile,v 1.4 2005/01/18 22:01:52 tv Exp $
# FreeBSD Id: Makefile,v 1.10 1997/04/27 16:06:15 ache Exp
#

DISTNAME=	rzip-2.0
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://rzip.samba.org/ftp/rzip/

MAINTAINER=	carton@Ivy.NET
HOMEPAGE=	http://rzip.samba.org/
COMMENT=	Create or extract .rz files, like gzip but smaller

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES

post-install:
	${LN} -f ${PREFIX}/bin/rzip ${PREFIX}/bin/runzip
	${RM} -f ${PREFIX}/man/man1/runzip.1
	${LN} -s ${PREFIX}/man/man1/rzip.1 ${PREFIX}/man/man1/runzip.1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
.  include "../../devel/libiberty/application.mk" # need asprintf(3)
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
