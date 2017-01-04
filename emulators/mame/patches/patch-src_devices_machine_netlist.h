$NetBSD: patch-src_devices_machine_netlist.h,v 1.1 2017/01/04 23:05:12 wiz Exp $

unsigned int * vs. uint8_t *

--- src/devices/machine/netlist.h.orig	2016-12-27 21:02:43.000000000 +0000
+++ src/devices/machine/netlist.h
@@ -529,7 +529,7 @@ protected:
 	virtual void device_start() override;
 	virtual void device_timer(emu_timer &timer, device_timer_id id, int param, void *ptr) override
 	{
-		m_param->setTo(m_data);
+		m_param->setTo((unsigned int *)m_data);
 	}
 
 private:
@@ -561,7 +561,7 @@ protected:
 	virtual void device_start() override;
 	virtual void device_timer(emu_timer &timer, device_timer_id id, int param, void *ptr) override
 	{
-		m_data = (*m_param)();
+		m_data = (unsigned char *)(*m_param)();
 	}
 
 private:
