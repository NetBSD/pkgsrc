# $NetBSD: Makefile,v 1.230 2020/06/22 06:24:15 wiz Exp $

DISTNAME=		mutt-1.14.4
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.mutt.org/pub/mutt/

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.mutt.org/
COMMENT=		Text-based MIME mail client with PGP & S/MIME support
LICENSE=		gnu-gpl-v2 OR gnu-gpl-v3 # or newer

DEPENDS+=		mime-types-[0-9]*:../../misc/mime-types

BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
BUILD_DEPENDS+=		lynx-[0-9]*:../../www/lynx

.include "../../mk/bsd.prefs.mk"

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/mutt
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--enable-external-dotlock
CONFIGURE_ARGS+=	--enable-pop
CONFIGURE_ARGS+=	--enable-imap
CONFIGURE_ARGS.SunOS+=	--disable-filemonitor
INFO_FILES=		yes

PYTHON_FOR_BUILD_ONLY=	tool
REPLACE_PYTHON+=	contrib/markdown2html

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD"
# Force sendmail to /usr/sbin to avoid postfix's
# ${LOCALBASE}/sbin/sendmail.  Should be enabled on all platforms which
# support mailwrapper.
CONFIGURE_ENV+=		SENDMAIL=/usr/sbin/sendmail
.endif

CONFIGURE_ARGS.SunOS+=	--without-wc-funcs

.include "options.mk"

LDFLAGS+=		${_STRIPFLAG_CC}

DOCDIR=			${PREFIX}/share/doc/mutt
EGDIR=			${PREFIX}/share/examples/mutt
CONF_FILES=		${EGDIR}/Muttrc ${PKG_SYSCONFDIR}/Muttrc
FILES_SUBST+=		DOCDIR=${DOCDIR}
INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	contrib/sample.muttrc
SUBST_FILES.paths+=	contrib/sample.muttrc-starter
SUBST_FILES.paths+=	doc/configuration.html
SUBST_FILES.paths+=	doc/gettingstarted.html
SUBST_FILES.paths+=	doc/instdoc.sh.in
SUBST_FILES.paths+=	doc/manual.html
SUBST_FILES.paths+=	doc/manual.xml.head
SUBST_FILES.paths+=	doc/mimesupport.html
SUBST_FILES.paths+=	doc/mutt.info
SUBST_FILES.paths+=	doc/mutt.texi
SUBST_FILES.paths+=	doc/muttrc.man
SUBST_FILES.paths+=	doc/reference.html
SUBST_SED.paths+=	-e "s,/usr/local,${PREFIX},g"
SUBST_STAGE.paths=	pre-configure

SPECIAL_PERMS+=		bin/mutt_dotlock ${REAL_ROOT_USER} mail 2551
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxslt/xsltproc-nonet.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
