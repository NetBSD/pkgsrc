# $NetBSD: Makefile,v 1.148 2004/10/03 00:12:53 tv Exp $

DISTNAME=	fetchmail-6.2.5
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://catb.org/~esr/fetchmail/ \
		http://sunsite.unc.edu/pub/Linux/system/mail/pop/

MAINTAINER=	frueauf@NetBSD.org
HOMEPAGE=	http://catb.org/~esr/fetchmail/
COMMENT=	Batch mail retrieval/forwarding utility for pop2, pop3, apop, imap

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_USES_MSGFMT=	yes

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-hesiod
USE_TBL=		yes
LDFLAGS+=		${CFLAGS}

.include "options.mk"

DOCDIR=		${PREFIX}/share/doc/fetchmail
RCD_SCRIPTS=	fetchmail

.include "../../devel/gettext-lib/buildlink3.mk"

post-extract:
	@${RM} -f ${WRKSRC}/intl/libintl.h
.if ${OPSYS} == "NetBSD"
	@${RM} -f ${WRKSRC}/md5.h
.endif

.if defined(REPLACE_KERBEROS_LIBS)
pre-configure:
	cd ${WRKSRC} && \
	for F in configure.in configure; do \
		${SED} -e "s/-lkrb -ldes/-lkrb -ldes -lcom_err -lroken/" \
			$$F > $$F.mod; \
		${MV} -f $$F.mod $$F; \
	done
	${CHMOD} a+x ${WRKSRC}/configure
.endif

post-build:
	for file in ${WRKSRC}/fetchmail.man; do				\
		${MV} -f $$file $$file.tbl;				\
		${TBL} $$file.tbl > $$file;				\
	done

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; for file in					\
		FAQ NOTES FEATURES README COPYING			\
		fetchmail-FAQ.html fetchmail-features.html		\
		design-notes.html;					\
	do								\
		${INSTALL_DATA} $$file ${DOCDIR};			\
	done

.include "../../mk/bsd.pkg.mk"
