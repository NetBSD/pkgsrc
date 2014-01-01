# $NetBSD: Makefile,v 1.14 2014/01/01 11:52:35 wiz Exp $

DISTNAME=	libvirt-0.9.3
PKGREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	http://libvirt.org/sources/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://libvirt.org/
COMMENT=	Virtualisation toolkit for host operating systems
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-vbox=no --sysconfdir=${EGDIR} --localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--without-macvtap
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes

PY_PATCHPLIST=		yes
PYTHON_PATCH_SCRIPTS+=	examples/python/domstart.py
PYTHON_PATCH_SCRIPTS+=	examples/python/domrestore.py
PYTHON_PATCH_SCRIPTS+=	examples/python/dominfo.py
PYTHON_PATCH_SCRIPTS+=	examples/python/domsave.py
PYTHON_PATCH_SCRIPTS+=	examples/python/esxlist.py
PYTHON_PATCH_SCRIPTS+=	examples/domain-events/events-python/event-test.py
PYTHON_PATCH_SCRIPTS+=	python/tests/create.py
PYTHON_PATCH_SCRIPTS+=	python/tests/error.py
PYTHON_PATCH_SCRIPTS+=	python/tests/uuid.py
PYTHON_PATCH_SCRIPTS+=	python/tests/basic.py
PYTHON_PATCH_SCRIPTS+=	python/tests/node.py
PYTHON_PATCH_SCRIPTS+=	python/libvirt-override.py
PYTHON_PATCH_SCRIPTS+=	python/libvirt-override-virStream.py
PYTHON_PATCH_SCRIPTS+=	python/libvirt-override-virConnect.py
PYTHON_PATCH_SCRIPTS+=	python/generator.py
PYTHON_PATCH_SCRIPTS+=	python/libvirt.py
PYTHON_PATCH_SCRIPTS+=	src/esx/esx_vi_generator.py
PYTHON_PATCH_SCRIPTS+=	docs/apibuild.py

EGDIR=			${PREFIX}/share/examples
CONF_FILES+=		${EGDIR}/libvirt/libvirtd.conf ${PKG_SYSCONFDIR}/libvirt/libvirtd.conf
CONF_FILES+=		${EGDIR}/libvirt/nwfilter/allow-arp.xml ${PKG_SYSCONFDIR}/libvirt/nwfilter/allow-arp.xml
CONF_FILES+=		${EGDIR}/libvirt/nwfilter/allow-dhcp-server.xml ${PKG_SYSCONFDIR}/libvirt/nwfilter/allow-dhcp-server.xml
CONF_FILES+=		${EGDIR}/libvirt/nwfilter/allow-dhcp.xml ${PKG_SYSCONFDIR}/libvirt/nwfilter/allow-dhcp.xml
CONF_FILES+=		${EGDIR}/libvirt/nwfilter/allow-incoming-ipv4.xml ${PKG_SYSCONFDIR}/libvirt/nwfilter/allow-incoming-ipv4.xml
CONF_FILES+=		${EGDIR}/libvirt/nwfilter/allow-ipv4.xml ${PKG_SYSCONFDIR}/libvirt/nwfilter/allow-ipv4.xml
CONF_FILES+=		${EGDIR}/libvirt/nwfilter/clean-traffic.xml ${PKG_SYSCONFDIR}/libvirt/nwfilter/clean-traffic.xml
CONF_FILES+=		${EGDIR}/libvirt/nwfilter/no-arp-spoofing.xml ${PKG_SYSCONFDIR}/libvirt/nwfilter/no-arp-spoofing.xml
CONF_FILES+=		${EGDIR}/libvirt/nwfilter/no-ip-multicast.xml ${PKG_SYSCONFDIR}/libvirt/nwfilter/no-ip-multicast.xml
CONF_FILES+=		${EGDIR}/libvirt/nwfilter/no-ip-spoofing.xml ${PKG_SYSCONFDIR}/libvirt/nwfilter/no-ip-spoofing.xml
CONF_FILES+=		${EGDIR}/libvirt/nwfilter/no-mac-broadcast.xml ${PKG_SYSCONFDIR}/libvirt/nwfilter/no-mac-broadcast.xml
CONF_FILES+=		${EGDIR}/libvirt/nwfilter/no-mac-spoofing.xml ${PKG_SYSCONFDIR}/libvirt/nwfilter/no-mac-spoofing.xml
CONF_FILES+=		${EGDIR}/libvirt/nwfilter/no-other-l2-traffic.xml ${PKG_SYSCONFDIR}/libvirt/nwfilter/no-other-l2-traffic.xml
CONF_FILES+=		${EGDIR}/libvirt/nwfilter/no-other-rarp-traffic.xml ${PKG_SYSCONFDIR}/libvirt/nwfilter/no-other-rarp-traffic.xml
CONF_FILES+=		${EGDIR}/libvirt/nwfilter/qemu-announce-self-rarp.xml ${PKG_SYSCONFDIR}/libvirt/nwfilter/qemu-announce-self-rarp.xml
CONF_FILES+=		${EGDIR}/libvirt/nwfilter/qemu-announce-self.xml ${PKG_SYSCONFDIR}/libvirt/nwfilter/qemu-announce-self.xml
CONF_FILES+=		${EGDIR}/libvirt/qemu/networks/autostart/default.xml ${PKG_SYSCONFDIR}/libvirt/qemu/networks/autostart/default.xml
CONF_FILES+=		${EGDIR}/libvirt/qemu/networks/default.xml ${PKG_SYSCONFDIR}/libvirt/qemu/networks/default.xml
CONF_FILES+=		${EGDIR}/logrotate.d/libvirtd ${PKG_SYSCONFDIR}/logrotate.d/libvirtd
CONF_FILES+=		${EGDIR}/logrotate.d/libvirtd.lxc ${PKG_SYSCONFDIR}/logrotate.d/libvirtd.lxc
CONF_FILES+=		${EGDIR}/logrotate.d/libvirtd.qemu ${PKG_SYSCONFDIR}/logrotate.d/libvirtd.qemu
CONF_FILES+=		${EGDIR}/logrotate.d/libvirtd.uml ${PKG_SYSCONFDIR}/logrotate.d/libvirtd.uml
CONF_FILES+=		${EGDIR}/sasl2/libvirt.conf ${PKG_SYSCONFDIR}/sasl2/libvirt.conf

AUTO_MKDIRS=		yes
RCD_SCRIPTS=            libvirtd

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
