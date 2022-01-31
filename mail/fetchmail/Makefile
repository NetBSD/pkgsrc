# $NetBSD: Makefile,v 1.203 2022/01/31 14:12:59 triaxx Exp $

# Note to updaters: mail/fetchmailconf reaches over here, make sure it builds.
DISTNAME=	fetchmail-6.4.27
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fetchmail/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.fetchmail.info/
COMMENT=	Batch mail retrieval/forwarding utility for pop2, pop3, apop, imap
LICENSE=	gnu-gpl-v1 AND gnu-gpl-v2 AND modified-bsd AND public-domain AND gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-hesiod
CONFIGURE_ENV+=		PYTHON=:
LDFLAGS+=		${CFLAGS}
USE_TOOLS+=		msgfmt tbl

LDFLAGS.Darwin+=	-lresolv
CFLAGS.Darwin+=		-DBIND_8_COMPAT -DHAVE_RESOLV_H

.include "options.mk"

TEST_TARGET=	check

DOCDIR=		${PREFIX}/share/doc/fetchmail
RCD_SCRIPTS=	fetchmail

INSTALLATION_DIRS+=	${DOCDIR}

.include "../../devel/gettext-lib/buildlink3.mk"

post-build:
	${MV} ${WRKSRC}/fetchmail.man ${WRKSRC}/fetchmail.man.tbl &&	\
	${TBL} ${WRKSRC}/fetchmail.man.tbl > ${WRKSRC}/fetchmail.man

post-install:
.for f in FAQ NOTES FEATURES README COPYING fetchmail-FAQ.html		\
                 fetchmail-features.html design-notes.html
	cd ${WRKSRC} &&							\
	${INSTALL_DATA} ${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
