# $NetBSD: Makefile,v 1.27 2018/08/22 09:46:17 wiz Exp $

DISTNAME=	CSP-0.34
PKGREVISION=	1
CATEGORIES=	security
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} cspguide.pdf
EXTRACT_ONLY=	${DISTFILES:N*.pdf}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple PKI Toolkit
LICENSE=	unlicense

DEPENDS+=	p5-Date-Calc>=5.4:../../devel/p5-Date-Calc
DEPENDS+=	p5-IPC-Run>=0.79:../../devel/p5-IPC-Run
DEPENDS+=	p5-Term-Prompt>=1.03:../../devel/p5-Term-Prompt

BUILD_DEFS+=	VARBASE
EGDIR=		${PREFIX}/share/examples

INSTALLATION_DIRS=	${PREFIX}/bin ${EGDIR}/csp/public_html/certs share/doc/csp

OWN_DIRS+=	${PKG_SYSCONFDIR}/csp/public_html/certs
REQD_FILES+=	${EGDIR}/csp/aliases.txt ${PKG_SYSCONFDIR}/csp/aliases.txt
REQD_FILES+=	${EGDIR}/csp/crl_extensions.conf ${PKG_SYSCONFDIR}/csp/crl_extensions.conf
REQD_FILES+=	${EGDIR}/csp/extensions.conf ${PKG_SYSCONFDIR}/csp/extensions.conf
REQD_FILES+=	${EGDIR}/csp/oids.conf ${PKG_SYSCONFDIR}/csp/oids.conf
REQD_FILES+=	${EGDIR}/csp/types.txt ${PKG_SYSCONFDIR}/csp/types.txt
REQD_FILES+=	${EGDIR}/csp/public_html/index.html.mpp ${PKG_SYSCONFDIR}/csp/public_html/index.html.mpp
REQD_FILES+=	${EGDIR}/csp/public_html/certs/cert.html.mpp ${PKG_SYSCONFDIR}/csp/public_html/certs/cert.html.mpp
REQD_FILES+=	${EGDIR}/csp/public_html/certs/expired.html.mpp ${PKG_SYSCONFDIR}/csp/public_html/certs/expired.html.mpp
REQD_FILES+=	${EGDIR}/csp/public_html/certs/index.html.mpp ${PKG_SYSCONFDIR}/csp/public_html/certs/index.html.mpp
REQD_FILES+=	${EGDIR}/csp/public_html/certs/revoked.html.mpp ${PKG_SYSCONFDIR}/csp/public_html/certs/revoked.html.mpp
REQD_FILES+=	${EGDIR}/csp/public_html/certs/valid.html.mpp ${PKG_SYSCONFDIR}/csp/public_html/certs/valid.html.mpp


SUBST_CLASSES+=		csp
SUBST_FILES.csp=	csp
SUBST_SED.csp=		-e s,@CSPHOME@,${PKG_SYSCONFDIR}/csp,
SUBST_SED.csp+=		-e s,@OPENSSL@,${BUILDLINK_PREFIX.openssl}/bin/openssl,
SUBST_STAGE.csp=	pre-configure

pre-install:
	${INSTALL_DATA} ${DISTDIR}/cspguide.pdf ${DESTDIR}${PREFIX}/share/doc/csp
	${INSTALL_DATA} ${WRKSRC}/ca/etc/aliases.txt ${DESTDIR}${EGDIR}/csp/aliases.txt
	${INSTALL_DATA} ${WRKSRC}/ca/etc/crl_extensions.conf ${DESTDIR}${EGDIR}/csp/crl_extensions.conf
	${INSTALL_DATA} ${WRKSRC}/ca/etc/extensions.conf ${DESTDIR}${EGDIR}/csp/extensions.conf
	${INSTALL_DATA} ${WRKSRC}/ca/etc/oids.conf ${DESTDIR}${EGDIR}/csp/oids.conf
	${INSTALL_DATA} ${WRKSRC}/ca/etc/types.txt ${DESTDIR}${EGDIR}/csp/types.txt
	${INSTALL_DATA} ${WRKSRC}/ca/etc/public_html/index.html.mpp ${DESTDIR}${EGDIR}/csp/public_html/index.html.mpp
	${INSTALL_DATA} ${WRKSRC}/ca/etc/public_html/certs/cert.html.mpp ${DESTDIR}${EGDIR}/csp/public_html/certs/cert.html.mpp
	${INSTALL_DATA} ${WRKSRC}/ca/etc/public_html/certs/expired.html.mpp ${DESTDIR}${EGDIR}/csp/public_html/certs/expired.html.mpp
	${INSTALL_DATA} ${WRKSRC}/ca/etc/public_html/certs/index.html.mpp ${DESTDIR}${EGDIR}/csp/public_html/certs/index.html.mpp
	${INSTALL_DATA} ${WRKSRC}/ca/etc/public_html/certs/revoked.html.mpp ${DESTDIR}${EGDIR}/csp/public_html/certs/revoked.html.mpp
	${INSTALL_DATA} ${WRKSRC}/ca/etc/public_html/certs/valid.html.mpp ${DESTDIR}${EGDIR}/csp/public_html/certs/valid.html.mpp

post-install:
	${LN} -sf ${DESTDIR}${PREFIX}/${PERL5_SUB_INSTALLVENDORBIN}/csp ${DESTDIR}${PREFIX}/bin/csp
	${RM} ${DESTDIR}${PREFIX}/${PERL5_SUB_INSTALLARCHLIB}/perllocal.pod

.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
