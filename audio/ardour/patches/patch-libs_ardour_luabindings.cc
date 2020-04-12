$NetBSD: patch-libs_ardour_luabindings.cc,v 1.1 2020/04/12 19:36:26 joerg Exp $

Avoid extensive intermediate object chains.

--- libs/ardour/luabindings.cc.orig	2020-04-11 23:24:29.090389555 +0000
+++ libs/ardour/luabindings.cc
@@ -807,7 +807,10 @@ LuaBindings::common (lua_State* L)
 		.addFunction ("writing", &AutomationList::writing)
 		.addFunction ("touch_enabled", &AutomationList::touch_enabled)
 		.endClass ()
+		.endNamespace ();
 
+	luabridge::getGlobalNamespace (L)
+		.beginNamespace ("ARDOUR")
 		.deriveClass <Location, PBD::StatefulDestructible> ("Location")
 		.addFunction ("name", &Location::name)
 		.addFunction ("locked", &Location::locked)
@@ -875,7 +878,10 @@ LuaBindings::common (lua_State* L)
 
 		.deriveWSPtrClass <AudioPort, Port> ("AudioPort")
 		.endClass ()
+		.endNamespace ();
 
+	luabridge::getGlobalNamespace (L)
+		.beginNamespace ("ARDOUR")
 		.deriveWSPtrClass <MidiPort, Port> ("MidiPort")
 		.addFunction ("input_active", &MidiPort::input_active)
 		.addFunction ("set_input_active", &MidiPort::set_input_active)
@@ -1013,7 +1019,10 @@ LuaBindings::common (lua_State* L)
 		.addFunction ("presentation_info_ptr", &Stripable::presentation_info_ptr)
 
 		.endClass ()
+		.endNamespace ();
 
+	luabridge::getGlobalNamespace (L)
+		.beginNamespace ("ARDOUR")
 		.deriveWSPtrClass <VCA, Stripable> ("VCA")
 		.addFunction ("full_name", &VCA::full_name)
 		.addFunction ("number", &VCA::number)
@@ -1116,7 +1125,10 @@ LuaBindings::common (lua_State* L)
 		.addFunction ("bounce_range", &Track::bounce_range)
 		.addFunction ("playlist", &Track::playlist)
 		.endClass ()
+		.endNamespace ();
 
+	luabridge::getGlobalNamespace (L)
+		.beginNamespace ("ARDOUR")
 		.deriveWSPtrClass <AudioTrack, Track> ("AudioTrack")
 		.endClass ()
 
@@ -1195,7 +1207,10 @@ LuaBindings::common (lua_State* L)
 		.addFunction ("source", &Region::source)
 		.addFunction ("control", static_cast<boost::shared_ptr<Evoral::Control>(Region::*)(const Evoral::Parameter&, bool)>(&Region::control))
 		.endClass ()
+		.endNamespace ();
 
+	luabridge::getGlobalNamespace (L)
+		.beginNamespace ("ARDOUR")
 		.deriveWSPtrClass <MidiRegion, Region> ("MidiRegion")
 		.addFunction ("do_export", &MidiRegion::do_export)
 		.addFunction ("midi_source", &MidiRegion::midi_source)
@@ -1298,7 +1313,10 @@ LuaBindings::common (lua_State* L)
 		.addData ("label", &ParameterDescriptor::label)
 		.addStaticFunction ("midi_note_name", &ParameterDescriptor::midi_note_name)
 		.endClass ()
+		.endNamespace ();
 
+	luabridge::getGlobalNamespace (L)
+		.beginNamespace ("ARDOUR")
 		.beginStdVector <boost::shared_ptr<ARDOUR::Processor> > ("ProcessorVector").endClass ()
 
 		.deriveWSPtrClass <Processor, SessionObject> ("Processor")
@@ -1408,6 +1426,10 @@ LuaBindings::common (lua_State* L)
 		.addFunction ("writable", &AutomationControl::writable)
 		.addFunction ("alist", &AutomationControl::alist)
 		.endClass ()
+		.endNamespace ();
+
+	luabridge::getGlobalNamespace (L)
+		.beginNamespace ("ARDOUR")
 
 		.deriveWSPtrClass <SlavableAutomationControl, AutomationControl> ("SlavableAutomationControl")
 		.addFunction ("add_master", &SlavableAutomationControl::add_master)
@@ -1501,6 +1523,10 @@ LuaBindings::common (lua_State* L)
 		// <std::list<boost::shared_ptr <AudioTrack> >
 		.beginStdList <boost::shared_ptr<AudioTrack> > ("AudioTrackList")
 		.endClass ()
+		.endNamespace ();
+
+	luabridge::getGlobalNamespace (L)
+		.beginNamespace ("ARDOUR")
 
 		// std::list<boost::shared_ptr <MidiTrack> >
 		.beginStdList <boost::shared_ptr<MidiTrack> > ("MidiTrackList")
@@ -1647,6 +1673,10 @@ LuaBindings::common (lua_State* L)
 		.deriveClass <TempoSection, MetricSection> ("TempoSection")
 		.addFunction ("c", (double(TempoSection::*)()const)&TempoSection::c)
 		.endClass ()
+		.endNamespace ();
+
+	luabridge::getGlobalNamespace (L)
+		.beginNamespace ("ARDOUR")
 
 		.deriveClass <MeterSection, MetricSection> ("MeterSection")
 		.addCast<Meter> ("to_meter")
@@ -1745,7 +1775,10 @@ LuaBindings::common (lua_State* L)
 		.addConst ("MeterPeak0dB", ARDOUR::MeterType(MeterPeak0dB))
 		.addConst ("MeterMCP", ARDOUR::MeterType(MeterMCP))
 		.endNamespace ()
+		.endNamespace ();
 
+	luabridge::getGlobalNamespace (L)
+		.beginNamespace ("ARDOUR")
 		.beginNamespace ("MeterPoint")
 		.addConst ("MeterInput", ARDOUR::MeterPoint(MeterInput))
 		.addConst ("MeterPreFader", ARDOUR::MeterPoint(MeterPreFader))
@@ -1846,7 +1879,10 @@ LuaBindings::common (lua_State* L)
 		.addConst ("RF64_WAV", ARDOUR::HeaderFormat(RF64_WAV))
 		.addConst ("MBWF", ARDOUR::HeaderFormat(MBWF))
 		.endNamespace ()
+		.endNamespace ();
 
+	luabridge::getGlobalNamespace (L)
+		.beginNamespace ("ARDOUR")
 		.beginNamespace ("InsertMergePolicy")
 		.addConst ("Reject", ARDOUR::InsertMergePolicy(InsertMergeReject))
 		.addConst ("Relax", ARDOUR::InsertMergePolicy(InsertMergeRelax))
