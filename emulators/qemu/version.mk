# $NetBSD: version.mk,v 1.18 2026/08/27 07:27:38 adam Exp $
#
# used by emulators/qemu
# used by sysutils/qemu-guest-agent

QEMU_VERSION?=	11.1.0

CHECK_PORTABILITY_SKIP+=	scripts/gitlab-map-update
