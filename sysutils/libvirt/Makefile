# $NetBSD: Makefile,v 1.66 2019/08/11 13:23:09 wiz Exp $

DISTNAME=		libvirt-1.2.9
PKGREVISION=		31
CATEGORIES=		sysutils
MASTER_SITES=		http://libvirt.org/sources/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://libvirt.org/
COMMENT=		Virtualisation toolkit for host operating systems
LICENSE=		gnu-lgpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-vbox=no --sysconfdir=${EGDIR} --localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--without-macvtap
CONFIGURE_ARGS+=	--without-polkit
USE_TOOLS+=		gmake pkg-config perl
USE_LIBTOOL=		yes

BUILD_DEFS+=		VARBASE

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-xml

PY_PATCHPLIST=		yes
REPLACE_PYTHON+=	docs/apibuild.py
REPLACE_PYTHON+=	src/esx/esx_vi_generator.py
REPLACE_PYTHON+=	src/hyperv/hyperv_wmi_generator.py
REPLACE_PYTHON+=	src/util/virkeycode-mapgen.py

EGDIR=			${PREFIX}/share/examples
CONF_FILES+=		${EGDIR}/libvirt/libvirtd.conf ${PKG_SYSCONFDIR}/libvirt/libvirtd.conf
CONF_FILES+=		${EGDIR}/libvirt/qemu/networks/autostart/default.xml ${PKG_SYSCONFDIR}/libvirt/qemu/networks/autostart/default.xml
CONF_FILES+=		${EGDIR}/libvirt/qemu/networks/default.xml ${PKG_SYSCONFDIR}/libvirt/qemu/networks/default.xml
CONF_FILES+=		${EGDIR}/logrotate.d/libvirtd ${PKG_SYSCONFDIR}/logrotate.d/libvirtd
CONF_FILES+=		${EGDIR}/logrotate.d/libvirtd.lxc ${PKG_SYSCONFDIR}/logrotate.d/libvirtd.lxc
CONF_FILES+=		${EGDIR}/logrotate.d/libvirtd.qemu ${PKG_SYSCONFDIR}/logrotate.d/libvirtd.qemu
CONF_FILES+=		${EGDIR}/logrotate.d/libvirtd.uml ${PKG_SYSCONFDIR}/logrotate.d/libvirtd.uml
CONF_FILES+=		${EGDIR}/sasl2/libvirt.conf ${PKG_SYSCONFDIR}/sasl2/libvirt.conf

AUTO_MKDIRS=		yes
RCD_SCRIPTS=		libvirtd

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
