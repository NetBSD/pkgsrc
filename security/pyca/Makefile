# $NetBSD: Makefile,v 1.18 2011/10/29 08:27:37 obache Exp $

# Date-based distfile name for pre-releases leading to 0.6.6.
DISTNAME=	pyca-20031118
PKGNAME=	${DISTNAME:S/pyca-/pyca-0.6.6./}
CATEGORIES=	security python
MASTER_SITES=	http://www.pyca.de/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pyca.de/
COMMENT=	Administration tools for X.509/PKIX CA
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFVAR=			openssl
PKG_SYSCONFSUBDIR=		openssl

.if ${OPSYS} == "NetBSD"
PKG_SYSCONFDIR.openssl?=	/etc/openssl
.endif

PYTHON_PATCH_SCRIPTS=	bin/*.py cgi-bin/*.py sbin/*.py

PYCA_SCRIPT_FIXUP_SED= \
	-e "s|/usr/local/pyca/pylib|${PREFIX}/lib/pyca|g"		\
	-e "s|/etc/openssl/openssl.cnf|${PKG_SYSCONFDIR}/openssl.cnf|g"	\
	-e "s|/home/.*/openssl.cnf|${PKG_SYSCONFDIR}/openssl.cnf|g"	\
	-e "s|/home/.*/pylib|${PREFIX}/lib/pyca|g"

INSTALLATION_DIRS=	bin lib/pyca/openssl libexec/cgi-bin sbin \
			share/doc/html/pyca/help share/doc/html/pyca/ssi \
			share/examples/pyca

pyca-script-fixup:
	cd ${WRKSRC}; for file in ${PYTHON_PATCH_SCRIPTS}; do \
		${SED} ${PYCA_SCRIPT_FIXUP_SED} \
			<$${file} >$${file}.fixed; \
		${MV} $${file}.fixed $${file}; \
	done

post-configure: pyca-script-fixup

do-install:
	cd ${WRKSRC}; for file in bin/*.py; do				\
		${INSTALL_SCRIPT} $${file} ${DESTDIR}${PREFIX}/bin;	\
	done
	cd ${WRKSRC}; for file in cgi-bin/*.py; do			\
		${INSTALL_SCRIPT} $${file} ${DESTDIR}${PREFIX}/libexec/cgi-bin;	\
	done
	cd ${WRKSRC}; for file in sbin/*.py; do				\
		${INSTALL_SCRIPT} $${file} ${DESTDIR}${PREFIX}/sbin;	\
	done
	cd ${WRKSRC}; for file in pylib/*.py; do			\
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/lib/pyca;	\
	done
	cd ${WRKSRC}; for file in pylib/openssl/*.py; do		\
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/lib/pyca/openssl;	\
	done
	cd ${WRKSRC}; for file in conf/*.cnf; do			\
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/share/examples/pyca;	\
	done
	cd ${WRKSRC}; for file in htdocs/*.html; do			\
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/share/doc/html/pyca;	\
	done
	cd ${WRKSRC}; for file in htdocs/help/*; do			\
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/share/doc/html/pyca/help; \
	done
	cd ${WRKSRC}; for file in htdocs/ssi/*.html; do			\
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/share/doc/html/pyca/ssi; \
	done

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
