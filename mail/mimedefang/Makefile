# $NetBSD: Makefile,v 1.65 2018/08/22 09:45:27 wiz Exp $

DISTNAME=		mimedefang-2.78
PKGREVISION=		4
CATEGORIES=		mail
MASTER_SITES=		http://www.mimedefang.org/static/

MAINTAINER=		pettai@NetBSD.org
HOMEPAGE=		http://www.mimedefang.org/
COMMENT=		To inspect/modify e-mail as it passes through your mail relay
LICENSE=		gnu-gpl-v2

DEPENDS+=		p5-Digest-SHA1>=2.00:../../security/p5-Digest-SHA1
DEPENDS+=		p5-HTML-Parser>=3.26:../../www/p5-HTML-Parser
DEPENDS+=		p5-HTML-Tagset>=3.03:../../www/p5-HTML-Tagset
DEPENDS+=		p5-IO-stringy>=2.108:../../devel/p5-IO-stringy
DEPENDS+=		p5-MailTools>=1.44:../../mail/p5-MailTools
#DEPENDS+=		{perl>=5.8.6,p5-MIME-Base64>=3.03}:../../converters/p5-MIME-Base64
DEPENDS+=		p5-MIME-tools>=5.413:../../mail/p5-MIME-tools
DEPENDS+=		spamassassin>=2.31:../../mail/spamassassin

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		perl:run
GNU_CONFIGURE=		YES
PKG_SYSCONFSUBDIR?=	mimedefang

DEFANG_SPOOLDIR?=	${VARBASE}/spool/MIMEDefang
DEFANG_USER?=		defang
DEFANG_GROUP?=		defang

PKG_GROUPS=		${DEFANG_GROUP}
PKG_USERS=		${DEFANG_USER}:${DEFANG_GROUP}

PKG_GROUPS_VARS+=	DEFANG_GROUP
PKG_USERS_VARS+=	DEFANG_USER

BUILD_DEFS+=		PKG_SYSCONFSUBDIR DEFANG_SPOOLDIR VARBASE

EGDIR=			${PREFIX}/share/examples/mimedefang
SHAREDIR=		${PREFIX}/share/mimedefang

FILES_SUBST+=		SHAREDIR=${SHAREDIR:Q}
FILES_SUBST+=		DEFANG_USER=${DEFANG_USER:Q}
FILES_SUBST+=		DEFANG_SPOOLDIR=${DEFANG_SPOOLDIR:Q}

RCD_SCRIPTS=		mimedefang-multiplexor mimedefang

OWN_DIRS_PERMS+=	${DEFANG_SPOOLDIR} ${DEFANG_USER} ${DEFANG_GROUP} 0700

CONF_FILES+=		${EGDIR}/mimedefang-filter ${PKG_SYSCONFDIR}/mimedefang-filter
CONF_FILES+=		${EGDIR}/sa-mimedefang.cf ${PKG_SYSCONFDIR}/sa-mimedefang.cf

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-confsubdir=
CONFIGURE_ARGS+=	--with-milterinc=${BUILDLINK_PREFIX.libmilter}/include
CONFIGURE_ARGS+=	--with-milterlib=${BUILDLINK_PREFIX.libmilter}/lib
CONFIGURE_ARGS+=	--with-spooldir=${DEFANG_SPOOLDIR:Q}
CONFIGURE_ARGS+=	--with-quarantinedir=${DEFANG_SPOOLDIR:Q}
CONFIGURE_ARGS+=	--with-user=${DEFANG_USER:Q}
# CONFIGURE_ARGS+=	--disable-anti-virus
#	list the paths where they _would_ be installed, so they
#	can be found at runtime. -- they have to be listed
#	in the environment, as the --enable-<> flags don't work
CONFIGURE_ENV+=		CLAMD=${PREFIX}/sbin/clamd
CONFIGURE_ENV+=		CLAMSCAN=${PREFIX}/bin/clamscan
CONFIGURE_ENV+=		FPROT=${PREFIX}/bin/f-prot
CONFIGURE_ENV+=		NAI=${PREFIX}/bin/uvscan

# Doesn't work with pth
PTHREAD_OPTS+=		require native

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man5 ${PKGMANDIR}/man7 ${PKGMANDIR}/man8
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/gen-ip-validator.pl ${DESTDIR}${SHAREDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/md-mx-ctrl ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mimedefang-multiplexor ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mimedefang ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/watch-mimedefang ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mimedefang.pl ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/md-mx-ctrl.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/mimedefang.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/mimedefang.pl.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/mimedefang-multiplexor.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/watch-mimedefang.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/mimedefang-filter.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/mimedefang-protocol.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7
	${INSTALL_DATA} ${WRKSRC}/examples/suggested-minimum-filter-for-windows-clients ${DESTDIR}${EGDIR}/mimedefang-filter
	${INSTALL_DATA} ${WRKSRC}/SpamAssassin/spamassassin.cf ${DESTDIR}${EGDIR}/sa-mimedefang.cf

.include "../../lang/perl5/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
