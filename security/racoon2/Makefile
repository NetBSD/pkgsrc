# $NetBSD: Makefile,v 1.16 2019/08/11 13:23:00 wiz Exp $
#

PKGREVISION=		2
CATEGORIES=		security net
#DISTNAME=		racoon2-20100526a
#MASTER_SITES=		ftp://ftp.racoon2.wide.ad.jp/pub/racoon2/
#EXTRACT_SUFX=		.tgz

DISTNAME=		racoon2
PKGNAME=		racoon2-20180701
MASTER_SITES= 		${MASTER_SITE_GITHUB:=zoulasc/}
GITHUB_PROJECT=		racoon2
GITHUB_TAG=		b2a193fc9875d1fb89c0a51690745379bc135fcf

MAINTAINER=		kamada@nanohz.org
HOMEPAGE=		http://www.racoon2.wide.ad.jp/
COMMENT=		IPsec key management system (IKEv2, IKEv1, and KINK)

GNU_CONFIGURE=		yes
INSTALL_UNSTRIPPED=	yes
USE_TOOLS+=		grep sed flex yacc
USE_TOOLS+=		gzip:run perl:run	# used by pskgen

# @perl_bindir@ will be /usr/pkgsrc/security/racoon2/work/.tools/bin/perl.
# REPLACE_PERL cannot be used, since @perl_bindir@ does not match its pattern.
REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	@perl_bindir@
REPLACE.perl.new=	${PERL5}
REPLACE_FILES.perl=	pskgen/pskgen.in

SUBST_CLASSES+=		cf-path
SUBST_STAGE.cf-path=	pre-configure
SUBST_MESSAGE.cf-path=	Fixing config file paths.
SUBST_FILES.cf-path=	samples/racoon2.conf.in samples/vals.conf.in
SUBST_SED.cf-path=	-e 's,"@prefix@/etc/racoon2/,"${PKG_SYSCONFDIR}/,g'

SUBST_CLASSES+=		hk-path
SUBST_STAGE.hk-path=	pre-configure
SUBST_MESSAGE.hk-path=	Fixing hook script paths.
SUBST_FILES.hk-path=	samples/child-up.in samples/child-down.in \
			samples/child-rekey.in \
			samples/ikesa-up.in samples/ikesa-down.in \
			samples/ikesa-rekey.in \
			samples/migration.in \
			samples/ph1-up.in samples/ph1-down.in
SUBST_SED.hk-path=	-e 's,cd @prefix@/etc/racoon2/,cd ${PKG_SYSCONFDIR}/,g'

PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

BUILD_DEFS+=		PKG_SYSCONFBASE
BUILD_DEFS+=		VARBASE

PKG_SYSCONFSUBDIR=	racoon2
CONF_FILES_PERMS=	${EGDIR}/default.conf ${PKG_SYSCONFDIR}/default.conf \
				${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 600
CONF_FILES_PERMS+=	${EGDIR}/racoon2.conf ${PKG_SYSCONFDIR}/racoon2.conf \
				${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 600
CONF_FILES_PERMS+=	${EGDIR}/vals.conf ${PKG_SYSCONFDIR}/vals.conf \
				${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 600
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} --enable-natt

MAKE_DIRS_PERMS+=	${VARBASE}/run/racoon2 ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700

RCD_SCRIPTS=		iked kinkd spmd racoon2
RCD_SCRIPT_SRC.iked=	${WRKSRC}/samples/rc.d-iked
RCD_SCRIPT_SRC.kinkd=	${WRKSRC}/samples/rc.d-kinkd
RCD_SCRIPT_SRC.spmd=	${WRKSRC}/samples/rc.d-spmd
RCD_SCRIPT_SRC.racoon2=	${WRKSRC}/samples/rc.d-racoon2
CONFIGURE_ARGS+=	--disable-startup-scripts

SAMPLE_CONFS=		default.conf racoon2.conf vals.conf \
			transport_ike.conf tunnel_ike.conf \
			tunnel_ike_natt.conf \
			transport_kink.conf tunnel_kink.conf \
			local-test.conf
SAMPLE_HOOKS=		child-up child-down child-rekey \
			ikesa-up ikesa-down ikesa-rekey \
			migration \
			ph1-up ph1-down
DOCS=			COPYRIGHT README NEWS \
			doc/INSTALL doc/USAGE doc/cfg-usage.txt \
			doc/config-usage.txt

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	for file in ${SAMPLE_CONFS}; do \
		${INSTALL_DATA} ${WRKSRC}/samples/$$file ${DESTDIR}${EGDIR}; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/hook
	${INSTALL_SCRIPT} ${WRKSRC}/samples/functions ${DESTDIR}${EGDIR}/hook
	for file in ${SAMPLE_HOOKS}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/samples/$$file ${DESTDIR}${EGDIR}/hook; \
		${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/hook/$$file.d; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/samples/00ikesaup_sample ${DESTDIR}${EGDIR}/hook/ikesa-up.d
	${INSTALL_SCRIPT} ${WRKSRC}/samples/00childup_sample ${DESTDIR}${EGDIR}/hook/child-up.d
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	for file in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${DESTDIR}${DOCDIR}; \
	done

.if !empty(PKG_OPTIONS:Mkinkd)
KRB5_ACCEPTED=		heimdal mit-krb5
BUILDLINK_API_DEPENDS.heimdal+= heimdal>=0.6.0
BUILDLINK_API_DEPENDS.mit-krb5+= mit-krb5>=1.4.0
.  include "../../mk/krb5.buildlink3.mk"
.endif

.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
