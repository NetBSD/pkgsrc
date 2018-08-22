# $NetBSD: Makefile,v 1.24 2018/08/22 09:46:29 wiz Exp $
#

DISTNAME=	sks-1.1.5
PKGREVISION=	13
CATEGORIES=	security
MASTER_SITES=	https://bitbucket.org/skskeyserver/sks-keyserver/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/skskeyserver/
COMMENT=	Self Replicating PGP Key Server
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.10.2
BUILDLINK_API_DEPENDS.db4+=	db4>=4.6.0

REPLACE_SH=	sks_build.sh

USE_TOOLS+=	gmake perl:run tar
BDB_ACCEPTED=	db4

EGDIR=		${PREFIX}/share/examples/sks

MAKE_ENV+=	LIBDB=-ldb4 \
		BDBINCLUDE=-I${BUILDLINK_DIR}/include \
		BDBLIB=-L${BUILDLINK_DIR}/lib \
		PREFIX=${PREFIX:Q} \
		MANDIR=${PREFIX:Q}/man

INSTALLATION_DIRS=	${PKGMANDIR}/man8 bin ${EGDIR}

.include "../../lang/ocaml/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} dep

post-install:
	cd ${WRKSRC} && ${MAKE_PROGRAM} sks.8
	${INSTALL_PROGRAM} ${WRKSRC}/sks ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sks_add_mail ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/sks_build.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sks.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/sampleConfig/aliases.sample \
				${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sampleConfig/crontab.sample \
				${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sampleConfig/mailsync ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sampleConfig/membership ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sampleConfig/procmailrc ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sampleConfig/sksconf.minimal \
				${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sampleConfig/sksconf.typical \
				${DESTDIR}${EGDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
