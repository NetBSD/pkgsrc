# $NetBSD: Makefile,v 1.17 2004/04/25 04:03:16 snj Exp $

DISTNAME=		mimedefang-2.40
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://www.mimedefang.org/static/

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://www.mimedefang.org/
COMMENT=		To inspect/modify e-mail as it passes through your mail relay

DEPENDS+=		p5-Digest-SHA1>=2.00:../../security/p5-Digest-SHA1
DEPENDS+=		p5-HTML-Parser>=3.26:../../www/p5-HTML-Parser
DEPENDS+=		p5-HTML-Tagset>=3.03:../../www/p5-HTML-Tagset
DEPENDS+=		p5-IO-stringy>=2.108:../../devel/p5-IO-stringy
DEPENDS+=		p5-MailTools>=1.44:../../mail/p5-MailTools
DEPENDS+=		p5-MIME-Base64>=2.11:../../converters/p5-MIME-Base64
DEPENDS+=		p5-MIME-tools>=5.411.1:../../mail/p5-MIME-tools
DEPENDS+=		spamassassin>=2.31:../../mail/spamassassin

USE_BUILDLINK3=		YES
USE_PERL5=		YES
GNU_CONFIGURE=		YES
PKG_SYSCONFSUBDIR?=	mimedefang

USE_PKGINSTALL=		YES
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

DEFANG_SPOOLDIR?=	/var/spool/MIMEDefang
DEFANG_USER?=		defang
DEFANG_GROUP?=		defang

PKG_GROUPS=		${DEFANG_GROUP}
PKG_USERS=		${DEFANG_USER}:${DEFANG_GROUP}

EGDIR=			${PREFIX}/share/examples/mimedefang
SHAREDIR=		${PREFIX}/share/mimedefang

FILES_SUBST+=		SHAREDIR=${SHAREDIR}
FILES_SUBST+=		DEFANG_USER=${DEFANG_USER}
FILES_SUBST+=		DEFANG_SPOOLDIR=${DEFANG_SPOOLDIR}

RCD_SCRIPTS=		mimedefang-multiplexor mimedefang

OWN_DIRS_PERMS+=	${DEFANG_SPOOLDIR} ${DEFANG_USER} ${DEFANG_GROUP} 0700

CONF_FILES+=		${EGDIR}/mimedefang-filter ${PKG_SYSCONFDIR}/mimedefang-filter
CONF_FILES+=		${EGDIR}/sa-mimedefang.cf ${PKG_SYSCONFDIR}/spamassassin/sa-mimedefang.cf

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-confsubdir=
CONFIGURE_ARGS+=	--with-milterinc=${BUILDLINK_PREFIX.libmilter}/include
CONFIGURE_ARGS+=	--with-milterlib=${BUILDLINK_PREFIX.libmilter}/lib
CONFIGURE_ARGS+=	--with-spooldir=${DEFANG_SPOOLDIR}
CONFIGURE_ARGS+=	--with-quarantinedir=${DEFANG_SPOOLDIR}
# CONFIGURE_ARGS+=	--disable-anti-virus
#	list the paths where they _would_ be installed, so they
#	can be found at runtime. -- they have to be listed
#	in the environment, as the --enable-<> flags don't work
CONFIGURE_ENV+=		CLAMD=${PREFIX}/sbin/clamd
CONFIGURE_ENV+=		CLAMSCAN=${PREFIX}/sbin/clamscan
CONFIGURE_ENV+=		FPROT=${PREFIX}/bin/f-prot
CONFIGURE_ENV+=		NAI=${PREFIX}/bin/uvscan

# Doesn't work with pth
PTHREAD_OPTS+=		require native

do-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/spamassassin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/gen-ip-validator.pl ${SHAREDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/md-mx-ctrl ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mimedefang-multiplexor ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mimedefang ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/watch-mimedefang ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mimedefang.pl ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/md-mx-ctrl.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/mimedefang.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/mimedefang.pl.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/mimedefang-multiplexor.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/watch-mimedefang.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/mimedefang-filter.5 ${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/mimedefang-protocol.7 ${PREFIX}/man/man7
	${INSTALL_DATA} ${WRKSRC}/examples/suggested-minimum-filter-for-windows-clients ${EGDIR}/mimedefang-filter
	${INSTALL_DATA} ${WRKSRC}/SpamAssassin/spamassassin.cf ${EGDIR}/sa-mimedefang.cf

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
