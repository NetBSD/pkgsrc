# $NetBSD: Makefile,v 1.1.1.1 2002/09/23 13:08:52 markd Exp $

DISTNAME=		mimedefang-2.21
CATEGORIES=		mail
MASTER_SITES=		http://www.roaringpenguin.com/mimedefang/

MAINTAINER=		markd@netbsd.org
HOMEPAGE=		http://www.roaringpenguin.com/mimedefang/
COMMENT=		To inspect/modify e-mail as it passes through your mail relay

DEPENDS+=		p5-Digest-SHA1>=2.00:../../security/p5-Digest-SHA1
DEPENDS+=		p5-HTML-Parser>=3.26:../../www/p5-HTML-Parser
DEPENDS+=		p5-HTML-Tagset>=3.03:../../www/p5-HTML-Tagset
DEPENDS+=		p5-IO-stringy>=2.108:../../devel/p5-IO-stringy
DEPENDS+=		p5-MailTools>=1.44:../../mail/p5-MailTools
DEPENDS+=		p5-MIME-Base64>=2.11:../../converters/p5-MIME-Base64
DEPENDS+=		p5-MIME-tools>=5.411a:../../mail/p5-MIME-tools
DEPENDS+=		spamassassin>=2.31:../../mail/spamassassin

USE_BUILDLINK2=		YES
USE_PERL5=		YES
GNU_CONFIGURE=		YES
PKG_SYSCONFSUBDIR?=	mimedefang

DEFANG_SPOOLDIR?=	/var/spool/MIMEDefang
DEFANG_USER?=		defang
DEFANG_GROUP?=		defang

PKG_GROUPS=		${DEFANG_GROUP}
PKG_USERS=		${DEFANG_USER}:${DEFANG_GROUP}

EGDIR=			${PREFIX}/share/examples/mimedefang
SHAREDIR=		${PREFIX}/share/mimedefang

INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL

FILES_SUBST+=		SHAREDIR=${SHAREDIR}
FILES_SUBST+=		DEFANG_USER=${DEFANG_USER}

OWN_DIRS_PERMS+=	${DEFANG_SPOOLDIR} ${DEFANG_USER} ${DEFANG_GROUP} 0700

CONF_FILES+=		${EGDIR}/mimedefang-filter ${PKG_SYSCONFDIR}/mimedefang-filter
CONF_FILES+=		${EGDIR}/sa-mimedefang.cf ${PKG_SYSCONFDIR}/spamassassin/sa-mimedefang.cf

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-confsubdir=
CONFIGURE_ARGS+=	--with-milterinc=${BUILDLINK_PREFIX.libmilter}/include
CONFIGURE_ARGS+=	--with-milterlib=${BUILDLINK_PREFIX.libmilter}/lib
CONFIGURE_ARGS+=	--with-spooldir=${DEFANG_SPOOLDIR}
CONFIGURE_ARGS+=	--with-quarantinedir=${DEFANG_SPOOLDIR}

do-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/spamassassin
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/gen-ip-validator.pl ${SHAREDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/mimedefang-multiplexor ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mimedefang ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mimedefang.pl ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mimedefang.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/mimedefang.pl.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/mimedefang-multiplexor.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/mimedefang-filter.5 ${PREFIX}/man/man5
	${INSTALL_DATA} ${WRKSRC}/mimedefang-protocol.7 ${PREFIX}/man/man7
	${INSTALL_DATA} ${WRKSRC}/examples/suggested-minimum-filter-for-windows-clients ${EGDIR}/mimedefang-filter
	${INSTALL_DATA} ${WRKSRC}/SpamAssassin/spamassassin.cf ${EGDIR}/sa-mimedefang.cf

.include "../../mail/libmilter/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
