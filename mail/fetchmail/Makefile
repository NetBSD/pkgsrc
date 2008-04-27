# $NetBSD: Makefile,v 1.166 2008/04/27 18:14:03 frueauf Exp $

DISTNAME=	fetchmail-6.3.8
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://download.berlios.de/fetchmail/	\
		http://download2.berlios.de/fetchmail/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fetchmail.berlios.de/
COMMENT=	Batch mail retrieval/forwarding utility for pop2, pop3, apop, imap

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-hesiod
CONFIGURE_ENV+=		PYTHON=:
LDFLAGS+=		${CFLAGS}
USE_TOOLS+=		msgfmt tbl

.if ${OPSYS} == "Darwin"
LDFLAGS+=		-lresolv
CFLAGS.Darwin+=		-DBIND_8_COMPAT -DHAVE_RESOLV_H
.endif

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
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}; for file in					\
		FAQ NOTES FEATURES README COPYING			\
		fetchmail-FAQ.html fetchmail-features.html		\
		design-notes.html;					\
	do								\
		${INSTALL_DATA} $$file ${DESTDIR}${DOCDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
