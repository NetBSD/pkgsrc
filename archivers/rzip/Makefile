# $NetBSD: Makefile,v 1.8 2006/02/14 20:58:18 adam Exp $

DISTNAME=	rzip-2.1
CATEGORIES=	archivers
MASTER_SITES=	http://rzip.samba.org/ftp/rzip/

MAINTAINER=	carton@Ivy.NET
HOMEPAGE=	http://rzip.samba.org/
COMMENT=	Create or extract .rz files, like gzip but smaller

GNU_CONFIGURE=	yes

post-install:
	${LN} -f ${PREFIX}/bin/rzip ${PREFIX}/bin/runzip
	${RM} -f ${PREFIX}/man/man1/runzip.1
	${LN} -s rzip.1 ${PREFIX}/man/man1/runzip.1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
.  include "../../devel/libiberty/application.mk" # need asprintf(3)
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
