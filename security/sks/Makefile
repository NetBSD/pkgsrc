# $NetBSD: Makefile,v 1.3 2012/07/08 09:56:09 sbd Exp $
#

DISTNAME=	sks-1.1.2
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://sks-keyserver.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://minskyprimus.net/sks/
COMMENT=	Self Replicating PGP Key Server
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.10.2
BUILDLINK_API_DEPENDS.db4+=	db4>=4.6.0

REPLACE_SH=	sks_build.sh

USE_TOOLS+=	gmake perl:run tar
BDB_ACCEPTED=	db4

MAKE_ENV+=	LIBDB=-ldb46 \
		BDBINCLUDE=-I${BUILDLINK_DIR}/include \
		BDBLIB=-L${BUILDLINK_DIR}/lib \
		PREFIX=${PREFIX:Q} \
		MANDIR=${PREFIX:Q}/man

INSTALLATION_DIRS=	${PKGMANDIR}/man8 bin

.include "../../lang/ocaml/buildlink3.mk"
.include "../../databases/db46/buildlink3.mk"

post-install:
	cd ${WRKSRC} && ${MAKE_PROGRAM} sks.8
	${INSTALL_PROGRAM} ${WRKSRC}/sks ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sks_add_mail ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/sks_build.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sks.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
