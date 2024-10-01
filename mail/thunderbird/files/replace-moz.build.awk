/^if CONFIG\[\"OS_TARGET\"\] == \"Android\":/{
	flag = 1;
	print $0;
	next;
}
/^if CONFIG\[\"OS_TARGET\"\] == \"Linux\":/{
	flag = 0;
	sub(/^if CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\":");
	print $0;
	next;
}
/^if CONFIG\[\"TARGET_CPU\"\] == \"arm\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/{
	flag = 0;
	sub(/^if CONFIG\[\"TARGET_CPU\"\] == \"arm\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"arm\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
	print $0;
	next;
}
/^if CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"arm\":/{
	flag = 0;
	sub(/^if CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"arm\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"arm\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
	print $0;
	next;
}
/^if CONFIG\[\"TARGET_CPU\"\] == \"aarch64\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/{
	flag = 0;
	sub(/^if CONFIG\[\"TARGET_CPU\"\] == \"aarch64\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"aarch64\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
	print $0;
	next;
}
/^if CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"aarch64\":/{
	flag = 0;
	sub(/^if CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"aarch64\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"aarch64\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
	print $0;
	next;
}
/^if CONFIG\[\"TARGET_CPU\"\] == \"x86\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/{
	flag = 0;
	sub(/^if CONFIG\[\"TARGET_CPU\"\] == \"x86\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"x86\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
	print $0;
	next;
}
/^if CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"x86\":/{
	flag = 0;
	sub(/^if CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"x86\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"x86\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
	print $0;
	next;
}
/^if CONFIG\[\"TARGET_CPU\"\] == \"x86_64\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/{
	flag = 0;
	sub(/^if CONFIG\[\"TARGET_CPU\"\] == \"x86_64\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"x86_64\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
	print $0;
	next;
}
/^if CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"x86_64\":/{
	flag = 0;
	sub(/^if CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"x86_64\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"x86_64\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
	print $0;
	next;
}
/^if CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"aarch64\":/{
	flag = 0;
	sub(/^if CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"aarch64\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"aarch64\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
}
/^if CONFIG\[\"TARGET_CPU\"\] == \"aarch64\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/{
	flag = 0;
	sub(/^if CONFIG\[\"TARGET_CPU\"\] == \"aarch64\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"aarch64\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
}
/^if CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"arm\":/{
	flag = 0;
	sub(/^if CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"arm\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"arm\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
}
/^if CONFIG\[\"TARGET_CPU\"\] == \"arm\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/{
	flag = 0;
	sub(/^if CONFIG\[\"TARGET_CPU\"\] == \"arm\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"arm\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
}
/^if CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"x86\":/{
	flag = 0;
	sub(/^if CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"x86\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"x86\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
}
/^if CONFIG\[\"TARGET_CPU\"\] == \"x86\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/{
	flag = 0;
	sub(/^if CONFIG\[\"TARGET_CPU\"\] == \"x86\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"x86\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
}
/^if CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"x86_64\":/{
	flag = 0;
	sub(/^if CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\" and CONFIG\[\"TARGET_CPU\"\] == \"x86_64\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"x86_64\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
}
/^if CONFIG\[\"TARGET_CPU\"\] == \"x86_64\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/{
	flag = 0;
	sub(/^if CONFIG\[\"TARGET_CPU\"\] == \"x86_64\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG\[\"TARGET_CPU\"\] == \"x86_64\" and CONFIG\[\"MOZ_X11\"\] == \"1\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
}
{
	if (flag != 1) {
		sub(/^    DEFINES\[\"WEBRTC_LINUX\"\] = True/, "    if CONFIG\[\"OS_TARGET\"\] == \"Linux\":\n        DEFINES\[\"WEBRTC_LINUX\"\] = True\n    else:\n        DEFINES\[\"WEBRTC_BSD\"\] = True");
		sub(/^if not CONFIG\[\"MOZ_DEBUG\"\] and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if not CONFIG[\"MOZ_DEBUG\"] and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
		sub(/^if CONFIG\[\"MOZ_DEBUG\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG[\"MOZ_DEBUG\"] == \"1\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
		sub(/^if CONFIG\[\"TARGET_CPU\"\] == \"aarch64\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG[\"TARGET_CPU\"] == \"aarch64\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
		sub(/^if CONFIG\[\"TARGET_CPU\"\] == \"x86\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG[\"TARGET_CPU\"] == \"x86\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
		sub(/^if CONFIG\[\"TARGET_CPU\"\] == \"x86_64\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG[\"TARGET_CPU\"] == \"x86_64\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
	}
	print $0;
}
