# $NetBSD: Makefile,v 1.122 2004/10/03 00:12:53 tv Exp $

DISTNAME=		mutt-1.4.2.1i
PKGNAME=		${DISTNAME:C/i$//}
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.mutt.org/mutt/ \
			ftp://ftp.stealth.net/pub/mirrors/ftp.mutt.org/pub/mutt/ \
			ftp://gd.tuwien.ac.at/infosys/mail/mutt/ \
			ftp://ftp.fu-berlin.de/unix/mail/mutt/

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.mutt.org/
COMMENT=		Text-based MIME mail client with PGP support

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/${DISTNAME:C/i$$//}
BUILD_USES_MSGFMT=	yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}			\
			--with-docdir=${PREFIX}/share/doc/mutt		\
			--without-included-gettext			\
			--enable-pop					\
			--enable-imap

.if (${OPSYS} == "SunOS")
CONFIGURE_ARGS+=	--without-wc-funcs
.endif

# There is a problem using /bin/sh on old NetBSD releases, so use /bin/ksh
# there.
#
.if !empty(MACHINE_PLATFORM:MNetBSD-1.[0-5]*-*)
CONFIGURE_ARGS+=	--with-exec-shell=/bin/ksh
.endif

.include "options.mk"

LDFLAGS+=		${_STRIPFLAG_CC}

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
DOCDIR=			${PREFIX}/share/doc/mutt
EGDIR=			${PREFIX}/share/examples/mutt
CONF_FILES=		${EGDIR}/Muttrc ${PKG_SYSCONFDIR}/Muttrc
SUPPORT_FILES=		${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types
FILES_SUBST+=		DOCDIR=${DOCDIR}

.if exists(${WRKSRC}/mutt_dotlock)
PLIST_SUBST+=		MUTT_DOTLOCK=
.else
PLIST_SUBST+=		MUTT_DOTLOCK="@comment "
.endif
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

# Fix some absolute paths in installed files.
post-build:
	for file in ${WRKSRC}/contrib/gpg.rc; do			\
		${MV} -f $$file $$file.save;				\
		${SED}	-e "s,/usr/bin/gpg,gpg,g"			\
			$$file.save > $$file;				\
	done
	for file in ${WRKSRC}/doc/mutt.man; do				\
		${MV} -f $$file $$file.save;				\
		${SED}	-e "s,/etc/,${PKG_SYSCONFDIR}/,g"		\
			-e "s,/usr/local/doc/mutt/,${DOCDIR}/,g"	\
			-e "s,/usr/local/,${PREFIX}/,g"			\
			$$file.save > $$file;				\
	done

# Pre-create some directories and symlinks used during the installation
# process.
#
pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${RM} -f ${DOCDIR}/samples
	${LN} -sf ${EGDIR} ${DOCDIR}/samples

.if (${PKG_INSTALLATION_TYPE} == "pkgviews")
post-install:
	${MV} ${PREFIX}/man/man5/mutt-mbox.5 ${PREFIX}/man/man5/mbox.5
.endif

.include "../../mk/bsd.pkg.mk"
